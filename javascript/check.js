function check(idrep,expected_val)
{
    elt = document.getElementById(idrep)
    val = elt.value;
    imgid = idrep.concat("img");
    imgquestion = document.getElementById(imgid)
    sha_val = CryptoJS.SHA256(val);
    if (sha_val == expected_val)
    {
    elt.style.border = "2px solid rgb(36,161,36)"
    elt.style.backgroundColor = "rgb(36,161,36,0.12)"
    imgquestion.src="https://fabricenativel.github.io/cpge-info/images/circle-check.svg";}

    else 
    {elt.style.border = "2px solid rgb(240,00,87)";
    elt.style.backgroundColor = "rgb(240,00,87,0.12)"
    imgquestion.src="https://fabricenativel.github.io/cpge-info/images/circle-xmark.svg"}
}

function imgreset(idrep)
{
    imgid = idrep.concat("img");
    imgquestion = document.getElementById(imgid);
    imgquestion.src="https://fabricenativel.github.io/cpge-info/images/circle-question.svg";
    elt = document.getElementById(idrep);
    elt.style.border = "2px solid #999999";
    elt.style.backgroundColor = "#F0F0F0";
    elt.value = "";
}