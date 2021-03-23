modded class PluginRecipesManagerBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new Recipe_RISAurora);				
		RegisterRecipe(new Recipe_HMDAurora);				
		RegisterRecipe(new Recipe_HMDAurora2);				
	}	
}