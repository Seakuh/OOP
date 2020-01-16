var request = require("request");
var user_id = "danienderle"
var token = "enderle"
var playlist_url = "https://api.spotify.com/v1/users/"+user_id+"/playlists"

request({url:playlists_url, headers:{"Autorization": token}}, function(err,res){
    if(res){
        var playlists = JSON.parse(res.body);
        var playlist_url = playlist_url[0].href;
        request({url:playlist_url, headers:{"Autorization": token}}, function(err,res){
            if(res){
                var playlist = JSON.parse(res.body);
                console.log("platlist: " = playlist.name);
                playlist.tracks.tracks.forEach(function(track){
                    console.log(track.track.name);

                });
            }
    
        })
    }
})