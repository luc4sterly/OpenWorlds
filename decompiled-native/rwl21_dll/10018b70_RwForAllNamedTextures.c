// 10018b70 RwForAllNamedTextures [Global]
// programa: RWL21.DLL

undefined4 RwForAllNamedTextures(undefined *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_4;
  
                    /* 0x18b70  110  RwForAllNamedTextures */
  if (param_1 == (undefined *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = FUN_10018c50(&local_4);
  if (0 < local_4) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar5 = 0;
    iVar2 = RwGetError();
    if (0 < local_4) {
      puVar4 = (undefined4 *)(iVar1 + 4);
      do {
        (*(code *)param_1)(*puVar4);
        iVar3 = FUN_1000cbd0();
        if (iVar3 != 0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar1);
          if (iVar2 != 0) {
            FUN_1000cb60(iVar2);
          }
          return 0;
        }
        puVar4 = puVar4 + 2;
        iVar5 = iVar5 + 1;
      } while (iVar5 < local_4);
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar1);
    FUN_1000cb60(iVar2);
    return 1;
  }
  return 1;
}


