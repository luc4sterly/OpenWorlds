// 10018f70 RwForAllNamedTexturesReal [Global]
// program: RWL21.DLL

undefined4 RwForAllNamedTexturesReal(undefined *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_4;
  
                    /* 0x18f70  114  RwForAllNamedTexturesReal */
  if (param_1 == (undefined *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = FUN_10018c50(&local_4);
  if (0 < local_4) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar4 = 0;
    iVar2 = RwGetError();
    if (0 < local_4) {
      puVar5 = (undefined4 *)(iVar1 + 4);
      do {
        (*(code *)param_1)(*puVar5,param_2);
        iVar3 = FUN_1000cbd0();
        if (iVar3 != 0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar1);
          if (iVar2 != 0) {
            FUN_1000cb60(iVar2);
          }
          return 0;
        }
        puVar5 = puVar5 + 2;
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_4);
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar1);
    FUN_1000cb60(iVar2);
    return 1;
  }
  return 1;
}


