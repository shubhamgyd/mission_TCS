#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <exception>
#include <sstream>
#include <iomanip>

struct Bundle
{
    std::string name;
    double price;
    int numComponents;
    std::vector<std::pair<int, std::string>> components;
};

struct Stock
{
    std::string name;
    double price;
};

class MarketWatchPortfolio
{
private:
    std::vector<Bundle> _bundles;
    std::unordered_map<std::string, Stock> _stocks;

public:
    MarketWatchPortfolio(std::vector<Bundle> const &bundles, std::unordered_map<std::string, Stock> const &stocks)
        : _bundles(bundles), _stocks(stocks)
    {
    }

    void ExecuteTrades()
    {
        for (auto const &bundle : _bundles)
        {
            double bundlePrice = CalculateBundlePrice(bundle);
            double individualStocksPrice = CalculateIndividualStocksPrice(bundle);

            if (bundlePrice < individualStocksPrice)
            {
                PrintTrade(bundle.name, "E", "B", bundlePrice);
            }
            else
            {
                PrintTrade(bundle.name, "E", "I", individualStocksPrice);
            }
        }
    }

private:
    double CalculateBundlePrice(Bundle const &bundle)
    {
        double totalPrice = 0.0;
        for (auto const &component : bundle.components)
        {
            auto stockIter = _stocks.find(component.second);
            if (stockIter == _stocks.end())
            {
                return -1.0; // Invalid component stock
            }
            totalPrice += component.first * stockIter->second.price;
        }
        return totalPrice;
    }

    double CalculateIndividualStocksPrice(Bundle const &bundle)
    {
        double totalPrice = 0.0;
        for (auto const &component : bundle.components)
        {
            auto stockIter = _stocks.find(component.second);
            if (stockIter == _stocks.end())
            {
                return -1.0; // Invalid component stock
            }
            totalPrice += component.first * stockIter->second.price;
        }
        return totalPrice;
    }

    void PrintTrade(std::string const &symbol, std::string const &executeOrPass, std::string const &bundleOrIndividualStock, double cost)
    {
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << symbol << " " << executeOrPass << " " << bundleOrIndividualStock << " " << cost << std::endl;
        return;
    }
};

class InputData
{
public:
    int numBundles;
    int numStocks;

    MarketWatchPortfolio LoadInput()
    {
        std::vector<Bundle> bundles;
        std::unordered_map<std::string, Stock> stocks;
        std::string line;
        int numStocks = -1;
        int numBundles = -1;
        while (std::getline(std::cin, line))
        {
            if (line.empty())
            {
                break;
            }
            std::stringstream ss;
            ss << line;
            if (numStocks == -1 && numBundles == -1)
            {
                ss >> numBundles >> numStocks;
                continue;
            }
            if (numBundles > 0)
            {
                Bundle bundle{};
                auto const &components = SplitString(line, " ");
                bundle.name = components[0];
                bundle.price = std::stod(components[1]);
                bundle.numComponents = std::stoi(components[2]);
                for (std::size_t i = 3; i < components.size() - 1; i = i + 2)
                {
                    auto const &c = std::make_pair(std::stoi(components[i]), components[i + 1]);
                    bundle.components.push_back(c);
                }
                bundles.push_back(bundle);
                numBundles--;
                continue;
            }
            Stock stock;
            ss >> stock.name >> stock.price;
            stocks.emplace(stock.name, stock);
        }

        return MarketWatchPortfolio{bundles, stocks};
    }

private:
    std::vector<std::string> SplitString(const std::string &str, const std::string &delimiter)
    {
        std::vector<std::string> strs;
        size_t startPos = 0;
        size_t endPos = 0;
        while ((endPos = str.find(delimiter, startPos)) != std::string::npos)
        {
            strs.emplace_back(str.substr(startPos, endPos - startPos));
            startPos = endPos + 1;
        }
        strs.emplace_back(str.substr(startPos));
        return strs;
    }
};

int main()
{
    InputData inputData;
    auto portfolio = inputData.LoadInput();
    portfolio.ExecuteTrades();
}
