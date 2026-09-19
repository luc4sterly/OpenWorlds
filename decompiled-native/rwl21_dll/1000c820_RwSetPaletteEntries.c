// 1000c820 RwSetPaletteEntries [Global]
// programa: RWL21.DLL

int RwSetPaletteEntries(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
                    /* 0xc820  429  RwSetPaletteEntries */
  if (param_3 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if (param_2 < 1) {
      FUN_1000cba0(0xb);
      return 0;
    }
    iVar3 = (**(code **)(PTR_DAT_1005b69c + 0x278))(param_1,param_2,param_3);
    if (iVar3 != 0) {
      puVar2 = *(undefined4 **)(PTR_DAT_1005b69c + 0xc);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          FUN_1000cba0(1);
        }
        else {
          puVar4 = puVar2 + 0x46;
          for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
          }
          if ((puVar2[0x8a] & 1) != 0) {
            puVar4 = puVar2 + 0x66;
            for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar4 = 0;
              puVar4 = puVar4 + 1;
            }
          }
          RwDamageCameraViewport((int)puVar2,0,0,puVar2[0x17],puVar2[0x18]);
        }
        (**(code **)(PTR_DAT_1005b69c + 0x280))(puVar2);
        puVar2 = puVar1;
      }
      return param_2;
    }
  }
  return 0;
}


