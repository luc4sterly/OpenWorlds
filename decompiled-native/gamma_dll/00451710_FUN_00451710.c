// 00451710 FUN_00451710 [Global]
// programa: gamma.dll

void __cdecl FUN_00451710(int param_1,undefined *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    if (param_2 != (undefined *)0x0) {
      uVar3 = *(undefined4 *)(param_1 + -8);
      uVar2 = *(uint *)(param_1 + -4);
      uVar1 = 0;
      if (uVar2 != 0) {
        do {
          (*(code *)param_2)(0xffffffff,uVar2,uVar3);
          uVar1 = uVar1 + 1;
        } while (uVar1 < uVar2);
      }
    }
    FUN_00451780((undefined4 *)(param_1 + -8));
  }
  return;
}


