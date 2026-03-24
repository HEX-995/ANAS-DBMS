const buttons = document.querySelectorAll(".button");
const body = document.querySelector("body");

buttons.forEach(function (button) {
  console.log(button);
  button.addEventListener("click", function (e) {
    
    // switch(e.target.id){
    //     case 'grey' : body.style.backgroundColor = e.target.id
    //     case 'blue' : body.style.backgroundColor = e.target.id
    //     case 'orange' : body.style.backgroundColor = e.target.id
    //     case 'red' : body.style.backgroundColor = e.target.id
    // }
    if (e.target.id === "grey") {
      body.style.backgroundColor = e.target.id;
    }
    if (e.target.id === "blue") {
      body.style.backgroundColor = e.target.id;
    }
    if (e.target.id === "orange") {
      body.style.backgroundColor = e.target.id;
    }
    if (e.target.id === "red") {
      body.style.backgroundColor = e.target.id;
    }
  });
});
