<h1>DBDdict</h1>
<h5>this is my first project in C++, it isn't too big but it's an attempt.</h5>
<h2>hello i hate C++</h2>

<p>
  This is supposed to be a dictionary for Dead By Daylight's survivor items and addons, and it shows their effects on said items and addons.
</p>

><h4>note: i was testing signed commits in the process of making this, most unsigned commits were from before or are from my chromebook </h4>

<hr></hr>

<h3>File Explanations</h3> 
<hr></hr>
<p>
  <ins><strong>Item.h & Addons.h</strong></ins> are providing a superclass and addon objects, respectively, to the actual item classes. <ins><strong>AddonList.json</strong></ins> is a JSON file containing all addons possible for DBD survivor items currently in the game (as of 5/11/22), as well as containing a single placeholder for ease of coding purposes. Interaction with JSON files is powered by the <em>nlohmann json</em> package. Next, the <ins><strong>BasicFunctions.h</strong></ins> file. This file provides some rudimentary functions for use in the primary file, though <ins><strong>Addons.h</strong></ins> contains some of these functions as well. Finally, the <ins><strong>Flashlight.h, Map.h, Key.h, Medkit.h, Toolbox.h</strong></ins> files are all for the purpose of instantiating the actual item objects, to store information about items you want to know the stats for.
</p>
