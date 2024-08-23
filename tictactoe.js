let boxes = document.querySelectorAll(".box");
let resetBtn = document.querySelector("#reset-btn");
let newBtn = document.querySelector("#new-btn");
let msgContainer = document.querySelector(".msg-container");
let msg = document.querySelector("#msg");

let count = 0; // For Draw
let turn0 = true; // player1

const winPatterns = [
    [0,1,2],
    [0,3,6],
    [0,4,8],
    [1,4,7],
    [2,5,8],
    [2,4,6],
    [3,4,5],
    [6,7,8],
];

const resetGame = () => {
    turn0 = true;
    enableBoxes();
    count = 0;
    msgContainer.classList.add("hide");
}
const textColor = (box) => {
    if (box.innerText === '0') {
        box.style.color = "blue";
    } else {
        box.style.color = "black";
    }
}
boxes.forEach((box) =>  {
    box.addEventListener("click", () =>{
        console.log("Box was clicked");
        if (turn0) {
            box.innerText = "0";
            textColor(box);
            turn0 = false;
        } else {
            box.innerText = "X";
            textColor(box);
            turn0 = true;
        }
        box.disabled = true;
        count++;

        let isWinner = checkWinner();
        if(count === 9 && !isWinner) {
            showDraw();
        }
    })
});

const enableBoxes = () =>{
    for (let box of boxes) {
        box.disabled = false;
        box.innerText = "";
    }
}
const disableBoxes = () => {
    for (let box of boxes) {
        box.disabled = true;
    }
}
const showWinner = (winner) => {
    msg.innerText = `Congratulation Winner is ${winner}`;
    msgContainer.classList.remove("hide");
}
const showDraw = () => {
    msg.innerText = `The game is draw`;
    msgContainer.classList.remove("hide");
    disableBoxes();
}
const checkWinner =  () => {
    for ( let pattern of winPatterns) {
        let pos1Val = boxes[pattern[0]].innerText;
        let pos2Val = boxes[pattern[1]].innerText;
        let pos3Val = boxes[pattern[2]].innerText;

        if(pos1Val != "" && pos2Val != "" && pos3Val != "") {
            if(pos1Val === pos2Val && pos2Val === pos3Val) {
                showWinner(pos1Val);
                return true;
            }
            }
        }
};

newBtn.addEventListener("click", resetGame);
resetBtn.addEventListener("click", resetGame); 