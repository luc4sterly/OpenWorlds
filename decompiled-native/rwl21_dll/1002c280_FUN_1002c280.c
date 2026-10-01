// 1002c280 FUN_1002c280 [Global]
// program: RWL21.DLL

undefined4 FUN_1002c280(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb8) + 0x18) + 0x14);
  }
  return uVar1;
}


