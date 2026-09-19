// 100023f0 FUN_100023f0 [Global]
// programa: RWDL6D21.DLL

void FUN_100023f0(int param_1)

{
  undefined4 uVar1;
  undefined1 local_c [12];
  
  if (*(int *)(DAT_1007bda8 + 0x14) == 8) {
    (**(code **)(DAT_1007bda8 + 0x264))(*(undefined4 *)(param_1 + 0x98),local_c);
    uVar1 = (**(code **)(DAT_1007bda8 + 0x284))(&stack0xffffffe8);
    *(undefined4 *)(param_1 + 0x9c) = uVar1;
  }
  return;
}


