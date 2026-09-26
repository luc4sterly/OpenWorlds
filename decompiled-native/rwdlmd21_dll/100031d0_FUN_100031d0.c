// 100031d0 FUN_100031d0 [Global]
// programa: rwdlmd21.dll

void FUN_100031d0(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_c [12];
  
  if ((DAT_1008705c != 0) && (DAT_10087058 == 0)) {
    puVar1 = (undefined1 *)(*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x2c) + 8) + 0x66a);
    iVar3 = 10;
    do {
      iVar4 = iVar3 + 1;
      *puVar1 = *(undefined1 *)((int)&DAT_10089f00 + iVar3);
      puVar1[-1] = *(undefined1 *)((int)&DAT_1008a000 + iVar3);
      puVar1[-2] = *(undefined1 *)((int)&DAT_10089df0 + iVar3);
      puVar1 = puVar1 + 4;
      iVar3 = iVar4;
    } while (iVar4 < 0xf5);
  }
  if (*(int *)(DAT_10089de0 + 0x14) == 8) {
    (**(code **)(DAT_10089de0 + 0x264))(*(undefined4 *)(param_1 + 0x98),local_c);
    uVar2 = (**(code **)(DAT_10089de0 + 0x284))(&stack0xffffffe8);
    *(undefined4 *)(param_1 + 0x9c) = uVar2;
  }
  return;
}


