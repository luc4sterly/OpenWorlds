// 10064da0 ___sbh_free_block [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_free_block(int param_1,int param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = param_1 + (param_2 - *(int *)(param_1 + 0x810) >> 0xc);
  *(char *)(iVar1 + 0x10) = *(char *)(iVar1 + 0x10) + *param_3;
  *param_3 = '\0';
  *(undefined1 *)(iVar1 + 0x410) = 0xf1;
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_10088730 = DAT_10088730 + 1, DAT_10088730 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


