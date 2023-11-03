document.getElementById("form").addEventListener("submit", function (event) {
  event.preventDefault();

  const fullName = document.getElementById("name").value;
  const email = document.getElementById("email").value;
  const password = document.getElementById("password").value;

  console.log("Full Name:", fullName);
  console.log("Email:", email);
  console.log("Password:", password);
});
