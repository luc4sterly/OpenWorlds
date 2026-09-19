// 100328a0 FUN_100328a0 [Global]
// programa: RWL21.DLL

undefined4 FUN_100328a0(int param_1,uint param_2)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x188) =
       (param_2 ^ *(uint *)(param_1 + 0x188)) & 6 ^ *(uint *)(param_1 + 0x188);
  if ((param_2 & 4) == 0) {
    uVar1 = (param_2 & 2) >> 1;
  }
  else {
    uVar1 = 2;
  }
  if (uVar1 == 0) {
    return 1;
  }
  if (uVar1 == 1) {
    *(undefined4 *)(param_1 + 0xac) = 0;
    *(undefined4 *)(param_1 + 0xa8) = 0;
    return 1;
  }
  if (uVar1 != 2) {
    return 0;
  }
  return 1;
}


