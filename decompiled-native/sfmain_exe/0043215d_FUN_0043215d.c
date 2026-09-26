// 0043215d FUN_0043215d [Global]
// programa: sfmain.exe

longlong __fastcall FUN_0043215d(undefined4 param_1,uint param_2)

{
  byte bVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  
  if (DAT_0043ea6c <= in_EAX) {
    return (ulonglong)param_2 << 0x20;
  }
  if ((int)in_EAX < 4) {
    iVar3 = in_EAX * 4;
    bVar1 = PTR_DAT_0043eac0[iVar3 + 1];
    if ((bVar1 & 0x40) == 0) {
      uVar2 = CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(bVar1,bVar1)) | 0x4000;
      PTR_DAT_0043eac0[iVar3 + 1] = (char)(uVar2 >> 8);
      lVar4 = FUN_00432296(uVar2,in_EAX);
      in_EAX = (uint)((ulonglong)lVar4 >> 0x20);
      if ((int)lVar4 != 0) {
        PTR_DAT_0043eac0[iVar3 + 1] = PTR_DAT_0043eac0[iVar3 + 1] | 0x20;
      }
    }
  }
  return CONCAT44(param_2,*(undefined4 *)(PTR_DAT_0043eac0 + in_EAX * 4));
}


