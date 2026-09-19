// 10018e80 RwForAllNamedTexturesLong [Global]
// programa: RWL21.DLL

undefined4 RwForAllNamedTexturesLong(undefined *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_8;
  int local_4;
  
                    /* 0x18e80  112  RwForAllNamedTexturesLong */
  if (param_1 == (undefined *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = FUN_10018c50(&local_8);
  if (0 < local_8) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar4 = 0;
    local_4 = RwGetError();
    if (0 < local_8) {
      puVar3 = (undefined4 *)(iVar1 + 4);
      do {
        (*(code *)param_1)(*puVar3,param_2);
        iVar2 = FUN_1000cbd0();
        if (iVar2 != 0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar1);
          if (local_4 != 0) {
            FUN_1000cb60(local_4);
          }
          return 0;
        }
        puVar3 = puVar3 + 2;
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_8);
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar1);
    FUN_1000cb60(local_4);
    return 1;
  }
  return 1;
}


