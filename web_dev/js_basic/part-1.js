let name = "dilshad";
// console.log(Array.from(name));
let key = Symbol("port");
let id = 23;

const user = {
  fname: "mohd dilshad ahmed",
  username: "dilshad1234",
  password: "1234",
  isloggedin: true,
  [key]: "hi there",
};
const user_2 = {
  fname: "mohd dilshad ahmed",
  username: "dilshad1234",
  password: "1234",
  isloggedin: true,
  [key]: "hi there",
};
user["fname"] = "anas siddiqui";
// console.log(user.hasOwnProperty('isloggedin'))
const user_3 = Object.assign(user, user_2);
// console.log(user_3)
const { password } = user_3;
console.log(password);
console.log(user_3);
console.log(addition(1, 2));
function addition(num1, num2) {
  return num1 + num2;
}
const subtract = function (num1, num2) {
  return num1 - num2;
};
const multiply = (num1, num2) => num1 * num2;
console.log(subtract(1, 2));
console.log(multiply(1, 2));
for (const i in user) {
  console.log(`${i} and ${user[i]}`);
}
