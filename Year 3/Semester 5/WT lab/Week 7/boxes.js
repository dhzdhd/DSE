const confirmBtn = document.getElementById("confirm");
confirmBtn.addEventListener("click", () => {
  console.log("hello");
  confirm("Confirm?");
});

const alertBtn = document.getElementById("alert");
alertBtn.addEventListener("click", () => {
  alert("Clicked button!");
});

const promptBtn = document.getElementById("prompt");
promptBtn.addEventListener("click", () => {
  const res = prompt("Prompt", "Yes");
  alert(res);
});
