// 100205a0 FUN_100205a0 [Global]
// programa: RWL21.DLL

void FUN_100205a0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (DAT_1005ac8c != 0) {
    puVar2 = &DAT_1005e008;
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + -1;
      (**(code **)(PTR_DAT_1005b69c + 0x358))(uVar1);
    } while ((undefined4 *)((int)&DAT_1005dfec + 3) < puVar2);
    DAT_1005ac8c = 0;
  }
  if (DAT_1005ac88 != 0) {
    (**(code **)(PTR_DAT_1005b69c + 0x358))(DAT_1005ac90);
    DAT_1005ac90 = 0;
    DAT_1005ac88 = 0;
  }
  return;
}


