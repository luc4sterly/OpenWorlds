// 100679c0 ___init_numeric [Global]
// programa: rwdlmd21.dll

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
  
  _Lc_type = (uint)DAT_10088e4a;
  if (DAT_10088748 != 0) {
    iVar1 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xe,0x10088e14,unaff_EDI);
    iVar2 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xf,0x10088e18,unaff_EDI);
    iVar3 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x10,0x10088e1c,unaff_EDI);
    fix_grouping(DAT_10088e1c);
    if ((iVar1 != 0 || iVar2 != 0) || iVar3 != 0) {
      _free(DAT_10088e14);
      _free(DAT_10088e18);
      _free(DAT_10088e1c);
      DAT_10088e14 = (void *)0x0;
      DAT_10088e18 = (void *)0x0;
      DAT_10088e1c = (char *)0x0;
      return -1;
    }
    if (*(undefined **)PTR_PTR_10089740 != &DAT_10089708) {
      _free(*(undefined **)PTR_PTR_10089740);
      _free(*(void **)(PTR_PTR_10089740 + 4));
      _free(*(void **)(PTR_PTR_10089740 + 8));
    }
    *(void **)PTR_PTR_10089740 = DAT_10088e14;
    *(void **)(PTR_PTR_10089740 + 4) = DAT_10088e18;
    *(char **)(PTR_PTR_10089740 + 8) = DAT_10088e1c;
    _DAT_100879f4 = 1;
    DAT_100879f0 = **(undefined1 **)PTR_PTR_10089740;
    return 0;
  }
  _free(DAT_10088e14);
  _free(DAT_10088e18);
  _free(DAT_10088e1c);
  DAT_10088e14 = (void *)0x0;
  DAT_10088e18 = (void *)0x0;
  DAT_10088e1c = (char *)0x0;
  pvVar4 = _malloc(2);
  *(void **)PTR_PTR_10089740 = pvVar4;
  if (*(undefined2 **)PTR_PTR_10089740 == (undefined2 *)0x0) {
    return -1;
  }
  **(undefined2 **)PTR_PTR_10089740 = DAT_1008656c;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_10089740 + 4) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_10089740 + 4) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_10089740 + 4) = 0;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_10089740 + 8) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_10089740 + 8) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_10089740 + 8) = 0;
  _DAT_100879f4 = 1;
  DAT_100879f0 = **(undefined1 **)PTR_PTR_10089740;
  return 0;
}


