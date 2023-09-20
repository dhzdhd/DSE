// Get the hour and minute hands
const hourHand = document.querySelector(".hour");
const minuteHand = document.querySelector(".minute");

function updateClock() {
  const now = new Date();

  const hourAngle = ((now.getHours() % 12) + now.getMinutes() / 60) * 30;

  const minuteAngle = now.getMinutes() * 6;

  hourHand.style.transform = `rotate(${hourAngle}deg)`;
  minuteHand.style.transform = `rotate(${minuteAngle}deg)`;

  setTimeout(updateClock, 1000);
}

updateClock();
