#ifndef __STRMAP_H__
#define __STRMAP_H__

static Int Compare(C Str &a, C Str &b) { return EE::CompareCS(a, b); }
static Bool Create(Str &data, C Str &key, Ptr user) { return true; }

#endif