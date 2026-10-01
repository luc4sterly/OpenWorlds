// 10030a90 FUN_10030a90 [Global]
// program: RWL21.DLL

undefined4 FUN_10030a90(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  DAT_1005ada8 = FUN_100371c0(s_scenelist_1005ae08,0x28);
  DAT_1005adac = FUN_100371c0(s_scenenodelist_1005adf8,0x68);
  puVar1 = FUN_10037030((int)DAT_1005ada8);
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
      FUN_10037010((int)DAT_1005ada8,puVar1);
      puVar1 = (undefined4 *)0x0;
    }
  }
  DAT_1005adb0 = puVar1;
  if (((DAT_1005ada8 != (undefined4 *)0x0) && (DAT_1005adac != (undefined4 *)0x0)) &&
     (puVar1 != (undefined4 *)0x0)) {
    return 1;
  }
  return 0;
}


