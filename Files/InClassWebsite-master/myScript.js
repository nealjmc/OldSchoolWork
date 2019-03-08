function loadDate(){
  var rightnow = new Date();
  var month = 0, todaysDate = "";
  month = rightnow.getMonth() + 1;
  todaysDate = month + '-' + rightnow.getDate() + '-' + rightnow.getFullYear();
  document.getElementById('date').innerHTML = "Todays Date: " + todaysDate;
}

function toggleColor(){
  document.getElementById('switchTypeTable').classList.toggle("switchTypeTableChange");
} 
