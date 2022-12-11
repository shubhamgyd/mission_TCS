"use strict";

async function fetchData() {
  await fetch("")
    .then((res) => res.json())
    .then((result) => {
      items = result.items;
      console.log(items);
    }),
    (error) => {
      console.log(error);
    };
}
