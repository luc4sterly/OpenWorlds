// 100023b0 FUN_100023b0 [Global]
// program: RWDL8D21.DLL

void FUN_100023b0(int param_1)

{
  undefined4 uVar1;
  undefined1 local_c [12];
  
  if (*(int *)(DAT_10077da8 + 0x14) == 8) {
    (**(code **)(DAT_10077da8 + 0x264))(*(undefined4 *)(param_1 + 0x98),local_c);
    uVar1 = (**(code **)(DAT_10077da8 + 0x284))(&stack0xffffffe8);
    *(undefined4 *)(param_1 + 0x9c) = uVar1;
  }
  return;
}


