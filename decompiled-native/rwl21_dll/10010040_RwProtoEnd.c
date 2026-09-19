// 10010040 RwProtoEnd [Global]
// programa: RWL21.DLL

undefined4 RwProtoEnd(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
                    /* 0x10040  310  RwProtoEnd */
  if (*DAT_1005dfcc == 0) {
    FUN_1000cba0(0x25);
    return 0;
  }
  if (((DAT_1005dfcc[1] != 0) && (DAT_1005dfcc[5] != 0)) && (DAT_1005dfcc[7] != 0)) {
    DAT_1005dfcc[1] = 0;
    puVar2 = FUN_1000f980();
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = DAT_1005dfcc + 5;
      iVar1 = ((undefined4 *)DAT_1005dfcc[5])[2];
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*(undefined4 *)DAT_1005dfcc[5]);
      if (*(undefined4 **)(*piVar3 + 4) != (undefined4 *)0x0) {
        RwDestroyClump(*(undefined4 **)(*piVar3 + 4));
      }
      FUN_10037010(DAT_1005a0d8,(undefined4 *)*piVar3);
      *piVar3 = iVar1;
      return 0;
    }
    *(undefined4 **)(DAT_1005dfcc[5] + 4) = puVar2;
    return 1;
  }
  FUN_1000cba0(0x22);
  return 0;
}


