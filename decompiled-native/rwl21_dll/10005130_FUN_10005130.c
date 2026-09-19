// 10005130 FUN_10005130 [Global]
// programa: RWL21.DLL

uint FUN_10005130(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
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


