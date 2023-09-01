// Given list
const choices = ["a", "b", "c", "d"];
// Take user input
let userChoice = prompt("Pick one from 'a', 'b', 'c', 'd': ");
// Iterate until input isn't matches
while (!choices.includes(userChoice)) {
  // alert to show invalid entry
  alert("Invalid entry! Please re-enter!");
  // Take again input
  userChoice = prompt("Pick one from 'a', 'b', 'c', 'd': ");
  alert("You picked " + userChoice);
}
