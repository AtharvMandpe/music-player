# music-player



Data Structures:

The code uses various data structures like vectors, maps, priority queues, and stacks.
Vectors (vector<vector<song>> v(6)) are used to store songs in a 2D grid-like structure.
Maps (map<ll, string> m, map<string, ll> gen, map<pair<ll, ll>, ll> views) are used to store mappings between song IDs, genres, and views.
Priority Queue (priority_queue<pair<ll, ll>> pq) is utilized to keep track of the top genre based on the number of views.
Stack (stack<pair<ll, ll>> prevv, nextt) is used to maintain the previous and next song selections.
Song Structure:

The song structure encapsulates attributes of a song such as name, genre, play count, etc.
User Interaction:

The program presents a menu-driven interface to the user, allowing them to choose from various options.
Options include playing a song, playing random songs, navigating to the previous or next song, adjusting volume, displaying the top genre, and exiting the program.
Play Song:

When the user selects to play a song, they input the coordinates of the song to be played.
The program increments the play count and updates genre statistics.
It also pushes the coordinates of the played song onto the prevv stack.
While the song is playing, the user has the option to pause, resume, or exit the song.
Previous and Next Song:

The program allows users to navigate to the previous or next song in the playlist.
When moving to the previous song, it pops the top song from the prevv stack, updates genre statistics, and pushes the song onto the nextt stack.
Similar actions are performed when moving to the next song.
Volume Control:

Users can adjust the volume by choosing to increase or decrease it.
The program limits the volume within the range of 0 to 100.
Top Genre:

The program displays the top genre based on the number of views accumulated by songs in that genre.
It utilizes the priority queue to fetch the top genre efficiently.
Play Random Songs:

Users can choose to play a set of random songs from the collection.
The program randomly selects songs and displays them to the user.
Exiting the Program:

Users have the option to exit the program at any time by selecting the corresponding menu option.
