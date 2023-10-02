document.getElementById('btn').addEventListener('click', (e) => {
    e.preventDefault()
    const input = document.getElementById('input').value;
    console.log(input);
    document.cookie = `name=${input};`;
    document.cookie = `date=${document.lastModified};`
}) 