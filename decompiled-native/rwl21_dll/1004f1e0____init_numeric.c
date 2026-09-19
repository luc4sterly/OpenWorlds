// 1004f1e0 ___init_numeric [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___init_numeric
   
   Library: Visual Studio 1998 Release */

int __cdecl ___init_numeric(threadlocinfo *_LocInfo)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *unaff_EDI;
  uint _Lc_type;
  
  _Lc_type = (uint)DAT_1005d07a;
  if (DAT_1005cd00 != 0) {
    iVar1 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xe,0x1005d044,unaff_EDI);
    iVar2 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xf,0x1005d048,unaff_EDI);
    iVar3 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x10,0x1005d04c,unaff_EDI);
    fix_grouping(DAT_1005d04c);
    if ((iVar1 != 0 || iVar2 != 0) || iVar3 != 0) {
      _free(DAT_1005d044);
      _free(DAT_1005d048);
      _free(DAT_1005d04c);
      DAT_1005d044 = (void *)0x0;
      DAT_1005d048 = (void *)0x0;
      DAT_1005d04c = (char *)0x0;
      return -1;
    }
    if (*(undefined **)PTR_PTR_1005d9a0 != &DAT_1005d968) {
      _free(*(undefined **)PTR_PTR_1005d9a0);
      _free(*(void **)(PTR_PTR_1005d9a0 + 4));
      _free(*(void **)(PTR_PTR_1005d9a0 + 8));
    }
    *(void **)PTR_PTR_1005d9a0 = DAT_1005d044;
    *(void **)(PTR_PTR_1005d9a0 + 4) = DAT_1005d048;
    *(char **)(PTR_PTR_1005d9a0 + 8) = DAT_1005d04c;
    _DAT_1005bb54 = 1;
    DAT_1005bb50 = **(undefined1 **)PTR_PTR_1005d9a0;
    return 0;
  }
  _free(DAT_1005d044);
  _free(DAT_1005d048);
  _free(DAT_1005d04c);
  DAT_1005d044 = (void *)0x0;
  DAT_1005d048 = (void *)0x0;
  DAT_1005d04c = (char *)0x0;
  pvVar4 = _malloc(2);
  *(void **)PTR_PTR_1005d9a0 = pvVar4;
  if (*(undefined2 **)PTR_PTR_1005d9a0 == (undefined2 *)0x0) {
    return -1;
  }
  **(undefined2 **)PTR_PTR_1005d9a0 = DAT_10052794;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_1005d9a0 + 4) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_1005d9a0 + 4) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_1005d9a0 + 4) = 0;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_1005d9a0 + 8) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_1005d9a0 + 8) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_1005d9a0 + 8) = 0;
  _DAT_1005bb54 = 1;
  DAT_1005bb50 = **(undefined1 **)PTR_PTR_1005d9a0;
  return 0;
}


