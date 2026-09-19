// 10037100 FUN_10037100 [Global]
// programa: RWL21.DLL

void FUN_10037100(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  for (puVar1 = DAT_1005b328; puVar2 = DAT_1005b334, puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    iVar3 = puVar1[6];
    while (iVar3 != 0) {
      iVar3 = puVar1[6];
      puVar1[6] = *(undefined4 *)(iVar3 + 0xff4);
      (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar3);
      puVar1[7] = puVar1[7] + -1;
      iVar3 = puVar1[6];
    }
    puVar1[4] = 0;
  }
  while (DAT_1005b334 = puVar2, puVar2 != (undefined4 *)0x0) {
    DAT_1005b334 = (undefined4 *)*puVar2;
    (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar2);
    puVar2 = DAT_1005b334;
  }
  while (iVar3 = FUN_10036fd0((int *)&DAT_1005b328), iVar3 != 0) {
    (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar3);
  }
  FUN_10036f80(&DAT_1005b328);
  DAT_1005b334 = (undefined4 *)0x0;
  DAT_1005b338 = 0;
  DAT_1005b33c = 0;
  return;
}


