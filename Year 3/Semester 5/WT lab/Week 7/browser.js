let windowObjectReference = null;

function openRequestedTab(url, windowName) {
  if (windowObjectReference === null || windowObjectReference.closed) {
    windowObjectReference = window.open("", "new");
  } else {
    windowObjectReference.focus();
  }
}