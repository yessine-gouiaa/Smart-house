
//***************temperature et humidité***************
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("temperature").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/lireTemperature", true);
    xhttp.send();
}, 1500);
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            
            document.getElementById("statecapvent").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/capvent", true);
    xhttp.send();
}, 1500);


setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("humidity").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lireHumidity", true);
    xhttp.send();
}, 1500);


function btnOncapvent() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onvent", true);
    xhttp.send();
}function btnOffcapvent() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offvent", true);
    xhttp.send();
}

setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("CVOS").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/cvo", true);
    xhttp.send();
}, 1500);







//*****************capteur incendie*****************
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("firestate").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/lirefirestate", true);
    xhttp.send();
}, 1500);

setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
           
            document.getElementById("statecapfire").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirecapfirestate", true);
    xhttp.send();
}, 1500);
//fonctiongetset button du capteur incendie
function btnOnincendie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onincendie", true);
    xhttp.send();
}

function btnOffincendie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offincendie", true);
    xhttp.send();
}

setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("CFOS").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/cfo", true);
    xhttp.send();
}, 1500);






//**********CAPTEUR GAZ***************** 
//----------fct etat capteur gaz----------
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("gazstate").innerHTML = this.responseText;
            
        }
    };

    xhttp.open("GET", "/liregazstate", true);
    xhttp.send();
}, 1500);

setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            
            document.getElementById("statecapgaz").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirecapgazstate", true);
    xhttp.send();
}, 1500);

//fonctiongetset button du capteur de gaz
function btnOngaz() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "ongaz", true);
    xhttp.send();
}

function btnOffgaz() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offgaz", true);
    xhttp.send();
}

setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("CGOS").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/cgo", true);
    xhttp.send();
}, 1500);



//**************************************************
//fonctiongetset button du capteur de gaz

//----------fct etat capteur gaz----------
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("temp").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lireTemp", true);
    xhttp.send();
},1500);
function tempup() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "tempup", true);
    xhttp.send();
}

function tempdown() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "tempdown", true);
    xhttp.send();
}


//**********CAPTEUR GAZ***************** 
//----------fct etat capteur pluie----------
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("rainstate").innerHTML = this.responseText;
            
        }
    };

    xhttp.open("GET", "/lirerainstate", true);
    xhttp.send();
}, 1500);

setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
           
            document.getElementById("statecaprain").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirecaprainstate", true);
    xhttp.send();
}, 1500);

//fonctiongetset button du capteur de gaz
function btnOnpluie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onrain", true);
    xhttp.send();
}

function btnOffpluie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offrain", true);
    xhttp.send();
}


setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("CROS").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/cro", true);
    xhttp.send();
}, 1500);

//**************************************************
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("servo fenetre").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/servofenetre", true);
    xhttp.send();
},1500);



setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("servo garage").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/servogarage", true);
    xhttp.send();
}, 1500);





//************led salon ***************** 
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("stateledsalon").innerHTML = this.responseText;
           
        }
    };

    xhttp.open("GET", "/lirEtatledsalon", true);
    xhttp.send();
}, 1500);

function btnOnledsalon() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onledsalon", true);
    xhttp.send();
}

function btnOffledsalon() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offledsalon", true);
    xhttp.send();
}






//*************** led cuisine *************** 
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("stateledcuisine").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirEtatledcuisine", true);
    xhttp.send();
}, 1500);


function btnOnledcuisine() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onledcuisine", true);
    xhttp.send();
}

function btnOffledcuisine() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offledcuisine", true);
    xhttp.send();
}


//********************* led garage******************** 
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("stateledgarage").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirEtatledgarage", true);
    xhttp.send();
}, 1500);

function btnOnledgarage() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onledgarage", true);
    xhttp.send();
}

function btnOffledgarage() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offledgarage", true);
    xhttp.send();
}


//********************led terrace*************
setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("stateledterrace").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirEtatledterrace", true);
    xhttp.send();
}, 1500);


setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("statecaplum").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirstatecaplum", true);
    xhttp.send();
}, 1500);


setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("ventstate").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/lirEtatvent", true);
    xhttp.send();
}, 1500);



setInterval(function ()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("distance").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "/ultrason", true);
    xhttp.send();
}, 1500);



function btnOnledterrace() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onledterrace", true);
    xhttp.send();
}

function btnOffledterrace() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offledterrace", true);
    xhttp.send();
}

//*************** ventilateur**************



//------------------------------------------------------

function btnOncapgaz() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "oncapgaz", true);
    xhttp.send();
}

function btnOffcapgaz() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offcapgaz", true);
    xhttp.send();
}

function btnOncappluie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "oncaprain", true);
    xhttp.send();
}

function btnOffcappluie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offcaprain", true);
    xhttp.send();
}

function btnOncapincendie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "oncapincendie", true);
    xhttp.send();
}

function btnOffcapincendie() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offcapincendie", true);
    xhttp.send();
}

function btnOncapvent() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "oncapvent", true);
    xhttp.send();
}function btnOffcapvent() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offcapvent", true);
    xhttp.send();
}


function garageon() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onservogarage", true);
    xhttp.send();
}function garageoff() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offservogarage", true);
    xhttp.send();
}

function fenetreon() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "onservofenetre", true);
    xhttp.send();
}function fenetreoff() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offservofenetre", true);
    xhttp.send();
}

function btnOncaplum() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "oncaplum", true);
    xhttp.send();
}function btnOffcaplum() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "offcaplum", true);
    xhttp.send();
}



// Charger le script EmailJS
(function() {
    emailjs.init("ply2j1X3pbXK-ekFT"); // Remplacez YOUR_USER_ID par votre identifiant utilisateur EmailJS
  })();
  
  // Fonction pour envoyer un e-mail
  function sendEmail() {
    // Définir les informations de l'e-mail
    var emailParams = {
      to_email: "yessine.gouiaa08@gmail.com", // Adresse e-mail du destinataire
      from_name: "Yessine Gouiaa", // Nom de l'expéditeur
      reply_to: "yessine.gouiaa@outlook.com", // Adresse e-mail de réponse
      message_html: "Ceci est un e-mail envoyé depuis EmailJS." // Corps de l'e-mail
    };
  
    // Envoyer l'e-mail en utilisant EmailJS
    emailjs.send("service_qhtnm2g", "template_64o1ufy", emailParams) // Remplacez YOUR_SERVICE_ID et YOUR_TEMPLATE_ID par vos identifiants de service et de modèle EmailJS
      .then(function(response) {
        console.log("E-mail envoyé avec succès !", response);
      }, function(error) {
        console.error("Erreur lors de l'envoi de l'e-mail :", error);
      });
  }
  
  // Appeler la fonction pour envoyer l'e-mail
  sendEmail();





