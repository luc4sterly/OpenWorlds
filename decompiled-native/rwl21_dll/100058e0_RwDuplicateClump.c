// 100058e0 RwDuplicateClump [Global]
// programa: RWL21.DLL

uint RwDuplicateClump(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
                    /* 0x58e0  74  RwDuplicateClump */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  puVar1 = FUN_10005180(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    uVar2 = RwGetClumpOwner((int)param_1);
    uVar2 = FUN_1002c120(uVar2,(uint)puVar3);
    return (uVar2 == 0) - 1 & (uint)puVar1;
  }
  return 0;
}


