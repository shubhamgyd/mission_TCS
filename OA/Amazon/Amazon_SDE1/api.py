import requests


def get_api_response(api_url):
    try:
        response = requests.get(api_url)
        response.raise_for_status()
        data = response.json()
        return data
    except requests.exceptions.RequestException as e:
        return None


def bestUniversityByCountry(country):
    api_url1 = "https://jsonmock.hackerrank.com/api/universities"
    api_response1 = get_api_response(api_url1)
    universities = []
    if api_response1 and api_response1["total_pages"] > 0:
        total_pages = api_response1["total_pages"]
        for page in range(total_pages):
            page = page + 1
            api_url = "https://jsonmock.hackerrank.com/api/universities?page={page}"
            api_response = get_api_response(api_url)
            if api_response:
                universities_in_country = [
                    univ
                    for univ in api_response["data"]
                    if univ["location"]["country"] == country
                ]
                if universities_in_country:
                    universities_in_country.sort(key=lambda x: int(x["rank_display"]))
                    best_university = universities_in_country[0]
                    universities.append(best_university)
    if not universities:
        return None
    universities.sort(key=lambda x: int(x["rank_display"]))
    best_university = universities[0]
    return best_university["university"]


country = "United States"
best_university = bestUniversityByCountry(country)

if best_university:
    print("University:", best_university)
