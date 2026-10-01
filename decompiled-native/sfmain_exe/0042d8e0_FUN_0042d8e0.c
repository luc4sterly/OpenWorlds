// 0042d8e0 FUN_0042d8e0 [Global]
// program: sfmain.exe

void __fastcall FUN_0042d8e0(undefined4 param_1)

{
  byte bVar1;
  undefined4 extraout_ECX;
  int extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  FUN_0042e727(param_1);
  if (*(int *)(extraout_EDX + 0x14) == 0) {
    if ((*(byte *)(extraout_EDX + 0xd) & 2) == 0) {
      if ((*(byte *)(extraout_EDX + 0xd) & 4) == 0) {
        *(undefined4 *)(extraout_EDX + 0x14) = 0x1000;
      }
      else {
        *(undefined4 *)(extraout_EDX + 0x14) = 1;
      }
    }
    else {
      *(undefined4 *)(extraout_EDX + 0x14) = 0x86;
    }
  }
  uVar3 = FUN_0042ba46(extraout_ECX,extraout_EDX);
  puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
  puVar2[2] = (int)uVar3;
  if ((int)uVar3 == 0) {
    puVar2[5] = 1;
    bVar1 = *(byte *)((int)puVar2 + 0xd) & 0xf8;
    *(byte *)((int)puVar2 + 0xd) = bVar1;
    puVar2[2] = puVar2 + 6;
    *(byte *)((int)puVar2 + 0xd) = bVar1 | 4;
  }
  else {
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 8;
  }
  puVar2[1] = 0;
  *puVar2 = puVar2[2];
  return;
}


