fetch('https://api.github.com/users/defunkt').then(function(response){
    return response.text();
}).then(function(text){
    $('#text_area').text(text);
});
