const form = document.querySelector("form");
const input = document.querySelector("input");
const result = document.querySelector(".result");
let randomNumber = Math.floor(Math.random() * 100) + 1;

let tries = 0;

form.addEventListener("submit", (event) => {
  event.preventDefault();
  tries++;

  if (tries === 5) {
    result.textContent = "5 tries over, number reset!";
    randomNumber = Math.floor(Math.random() * 100) + 1;
    tries = 0;

    setTimeout(() => {
      result.textContent = "";
    }, 1000);
  } else {
    const guess = parseInt(input.value);
    if (guess === randomNumber) {
      result.textContent = "Congratulations! You guessed the number!";
    } else if (guess < randomNumber) {
      result.textContent = "Too low! Try again.";
    } else {
      result.textContent = "Too high! Try again.";
    }
  }

  input.value = "";
});
