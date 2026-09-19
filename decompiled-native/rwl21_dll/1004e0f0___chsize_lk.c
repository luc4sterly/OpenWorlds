// 1004e0f0 __chsize_lk [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __chsize_lk
   
   Library: Visual Studio 1998 Release */

int __chsize_lk(void)

{
  DWORD DVar1;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  ulong *puVar5;
  int *piVar6;
  HANDLE hFile;
  BOOL BVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint in_stack_0000100c;
  int in_stack_00001010;
  
  FUN_10045470();
  iVar9 = 0;
  DVar1 = __lseek_lk(in_stack_0000100c,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = __lseek_lk(in_stack_0000100c,0,2), DVar2 == 0xffffffff)) {
    return -1;
  }
  uVar10 = in_stack_00001010 - DVar2;
  if ((int)uVar10 < 1) {
    if ((int)uVar10 < 0) {
      __lseek_lk(in_stack_0000100c,in_stack_00001010,0);
      hFile = (HANDLE)__get_osfhandle(in_stack_0000100c);
      BVar7 = SetEndOfFile(hFile);
      iVar9 = -(uint)(BVar7 == 0);
      if (iVar9 == -1) {
        piVar6 = FUN_100490e0();
        *piVar6 = 0xd;
        puVar5 = FUN_100490f0();
        DVar2 = GetLastError();
        *puVar5 = DVar2;
      }
    }
  }
  else {
    puVar11 = (undefined4 *)&stack0x00000008;
    for (iVar8 = 0x400; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    iVar8 = __setmode_lk(in_stack_0000100c,0x8000);
    do {
      uVar3 = 0x1000;
      if ((int)uVar10 < 0x1000) {
        uVar3 = uVar10;
      }
      iVar4 = __write_lk(in_stack_0000100c,&stack0x00000008,uVar3);
      if (iVar4 == -1) {
        puVar5 = FUN_100490f0();
        if (*puVar5 == 5) {
          piVar6 = FUN_100490e0();
          *piVar6 = 0xd;
        }
        iVar9 = -1;
        break;
      }
      uVar10 = uVar10 - iVar4;
    } while (0 < (int)uVar10);
    __setmode_lk(in_stack_0000100c,iVar8);
  }
  __lseek_lk(in_stack_0000100c,DVar1,0);
  return iVar9;
}


