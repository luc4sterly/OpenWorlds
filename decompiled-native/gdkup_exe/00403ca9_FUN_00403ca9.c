// 00403ca9 FUN_00403ca9 [Global]
// program: gdkup.exe

void __fastcall FUN_00403ca9(undefined4 param_1)

{
  byte bVar1;
  uint in_EAX;
  int iVar2;
  longlong lVar3;
  
  if ((*(byte *)(in_EAX + 0xd) & 0x20) == 0) {
    lVar3 = FUN_00405618(param_1,in_EAX);
    iVar2 = (int)((ulonglong)lVar3 >> 0x20);
    if ((int)lVar3 != 0) {
      bVar1 = *(byte *)(iVar2 + 0xd);
      *(byte *)(iVar2 + 0xd) = bVar1 | 0x20;
      if ((bVar1 & 7) == 0) {
        *(byte *)(iVar2 + 0xd) = bVar1 | 0x22;
      }
    }
  }
  return;
}


