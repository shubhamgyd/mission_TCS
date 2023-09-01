import React, { useEffect, useState } from "react";

const GetData = () => {
  const [data, setData] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch("https://api.publicapis.org/entries");
        const jsonData = await response.json();
        setData(jsonData);
        setLoading(false);
      } catch (error) {
        console.error("Error fetching data:", error);
      }
    };

    fetchData();
  }, []);

  if (loading) {
    return <div>Loading...</div>;
  }
  const entries1 = data["entries"];
  console.log(entries1);
  return (
    <div>
      <h1>List of Items:</h1>
      <ul>
        {entries1.map((item, index) => (
          <table>
            <tbody>
              {Object.entries(item).map(([key, value]) => (
                <tr key={key}>
                  <td>{key}</td>
                  <td>{value}</td>
                </tr>
              ))}
            </tbody>
            <br></br>
          </table>
        ))}
      </ul>
      {/* <pre>{JSON.stringify(data, null, 2)}</pre> */}
    </div>
  );
};

export default GetData;
