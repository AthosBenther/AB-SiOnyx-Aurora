// modded class ComponentEnergyManager
// {
//     protected int m_EnergyLevel;

//     void ComponentEnergyManager()
//     {
//         RegisterNetSyncVariableInt("m_EnergyLevel", 0, 4);
//     }

//     override void OnEnergyConsumed()
//     {
//         super.OnEnergyConsumed();

//         int energy = GetEnergy0To100();

//         energy = Math.Floor(energy / 25);
        
//         if (energy!= M_EnergyLevel)
//         {
//             m_EnergyLevel = energy;
//             SetSynchDirty();
//         }
//     }

//     int GetEnergyLevel()
//     {
//         return m_EnergyLevel;
//     }
// }