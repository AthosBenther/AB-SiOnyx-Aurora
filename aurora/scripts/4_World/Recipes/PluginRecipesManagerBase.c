modded class PluginRecipesManagerBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new Recipe_RISAurora);				
		RegisterRecipe(new Recipe_HMDAurora);				
		RegisterRecipe(new Recipe_HMDAurora2);

		RegisterRecipe(new Dismantle_RISAurora);				
		RegisterRecipe(new Dismantle_HMDAurora);				
		RegisterRecipe(new Dismantle_HMDAurora2);
	}	
}