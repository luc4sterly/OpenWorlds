// 10038d20 RwStopDisplayDevice [Global]
// programa: RWL21.DLL

undefined4 RwStopDisplayDevice(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 *local_8;
  
                    /* 0x38d20  499  RwStopDisplayDevice */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    uVar3 = 0;
  }
  else {
    local_8 = *(undefined4 **)(PTR_DAT_1005b69c + 0xc);
    while (local_8 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_8;
      RwDestroyCamera(local_8);
      local_8 = puVar1;
    }
    *(undefined4 *)(PTR_DAT_1005b69c + 0xc) = 0;
    pcVar4 = RwDestroyClump;
    iVar2 = RwDefaultScene();
    RwForAllClumpsInScene(iVar2,pcVar4);
    pcVar4 = RwDestroyLight;
    iVar2 = RwDefaultScene();
    RwForAllLightsInScene(iVar2,pcVar4);
    RwTextureDictEnd();
    FUN_1001bcb0();
    (**(code **)(param_1 + 0x27c))(param_1);
    uVar3 = 1;
  }
  return uVar3;
}


