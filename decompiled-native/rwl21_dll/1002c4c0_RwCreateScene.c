// 1002c4c0 RwCreateScene [Global]
// program: RWL21.DLL

undefined4 * RwCreateScene(void)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x2c4c0  44  RwCreateScene */
  puVar1 = FUN_10037030(DAT_1005ada8);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
  }
  else {
    puVar1[3] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 999999;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(4);
    puVar1[3] = iVar2;
    if (iVar2 == 0) {
      FUN_1000cba0(3);
      FUN_10037010(DAT_1005ada8,puVar1);
      return (undefined4 *)0x0;
    }
  }
  return puVar1;
}


