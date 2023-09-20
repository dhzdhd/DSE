let windowObjectReference = null;

function openRequestedTab(url, windowName) {
  if (windowObjectReference === null || windowObjectReference.closed) {
    windowObjectReference = window.open("", "new");
    windowObjectReference.document.write("<h1>Hello, world!</h1>");
  } else {
    windowObjectReference.focus();
  }
}

const button = document.querySelector(".button");
button.addEventListener("click", () => {
  openRequestedTab("https://www.example.com", "new");
});
