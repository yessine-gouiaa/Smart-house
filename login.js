let username = "0"; // Définir le nom d'utilisateur par défaut
let password = "0"; // Définir le mot de passe par défaut

const loginForm = document.getElementById("login-form");
const loginButton = document.getElementById("login-form-submit");
const loginErrorMsg = document.getElementById("login-error-msg");

loginButton.addEventListener("click", (e) => {
    e.preventDefault();
    const enteredUsername = loginForm.username.value;
    const enteredPassword = loginForm.password.value;

    if (enteredUsername === username && enteredPassword === password) {
        // Redirection vers une autre page si les informations de connexion sont correctes
        window.location.href = "select.html"; // Remplacez "lien_vers_autre_page.html" par le lien de votre page souhaitée
    } else {
        loginErrorMsg.style.opacity = 1;
    }
});



//changement du ot de passe et username
function changeCredentials(newUsername, newPassword) {
    username = newUsername;
    password = newPassword;
    alert("Le nom d'utilisateur et le mot de passe ont été changés avec succès !");
}

// Fonction pour récupérer et mettre à jour les valeurs des champs de saisie
function updateInputFields() {
    document.getElementById("username-field").value = username;
    document.getElementById("password-field").value = password;
}

// Écouteur d'événement pour le clic sur le bouton "Changer le mot de passe"
document.getElementById("change-password-button").addEventListener("click", function() {
    // Demander à l'utilisateur de saisir un nouveau nom d'utilisateur et un nouveau mot de passe
    const newUsername = prompt("Entrez un nouveau nom d'utilisateur :");
    const newPassword = prompt("Entrez un nouveau mot de passe :");

    // Vérifier si l'utilisateur a saisi de nouvelles valeurs
    if (newUsername !== null && newPassword !== null) {
        // Appeler la fonction pour changer le nom d'utilisateur et le mot de passe
        changeCredentials(newUsername, newPassword);
        // Mettre à jour les valeurs des champs de saisie avec les nouvelles valeurs
        updateInputFields();
       
    }
});








