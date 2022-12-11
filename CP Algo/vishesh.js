console.log("Welcome to AnSaVi Gaming");
let end = "y";
var user_score = 0;
var computer_score = 0;

while (end == "y" || end == "Y") {
  const readline = require("readline");
  const r1 = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });
  var possible_action = ["Rock", "Paper", "Scissor"];
  var user_action = async function inputUserAction() {
    var myPromise = new Promise(
      r1.question("Enter your choice Rock, Paper or Scissor", (answer) => {
        return answer;
      })
    );
    var result = await myPromise;
    return result;
  };
  user_action();

  console.log(user_action);
  const computer_action = Math.floor(Math.random() * possible_action.length);
  console.log(computer_action);

  // r1.question("Would you like to continue.... If yes press 'y' else 'q'...",function(string) {
  //     end = string;

  // });
}
