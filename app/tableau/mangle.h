/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */




#define MANGLE_MAX (511)

static 
const 
int 
mangle_random[MANGLE_MAX] = {
3,
83,
150,
151,
152,
156,
58,
140,
153,
141,
100,
114,
154,
155,
204,
205,
206,
207,
197,
198,
199,
208,
145,
189,
190,
191,
192,
193,
194,
202,
211,
212,
213,
146,
147,
148,
195,
196,
200,
201,
149,
142,
203,
209,
210,
143,
144,
157,
59,
60,
86,
4,
5,
456,
6,
103,
57,
10,
46,
477,
478,
33,
115,
480,
12,
43,
55,
66,
67,
44,
47,
11,
101,
9,
102,
45,
19,
494,
495,
496,
56,
62,
63,
64,
65,
30,
21,
22,
0,
23,
24,
39,
40,
41,
42,
71,
72,
73,
74,
27,
28,
29,
116,
117,
479,
31,
61,
84,
85,
16,
17,
497,
498,
20,
18,
32,
34,
35,
36,
37,
48,
49,
25,
26,
38,
50,
51,
52,
53,
54,
68,
69,
70,
75,
76,
77,
78,
79,
80,
81,
82,
13,
14,
15,
87,
88,
89,
90,
91,
92,
93,
94,
95,
96,
97,
98,
99,
104,
105,
106,
107,
108,
109,
110,
111,
112,
113,
118,
119,
120,
121,
122,
123,
124,
125,
126,
127,
128,
129,
130,
131,
132,
171,
172,
173,
174,
175,
176,
177,
178,
179,
180,
181,
182,
183,
184,
185,
186,
187,
188,
214,
215,
216,
217,
218,
219,
220,
221,
222,
223,
224,
225,
226,
227,
228,
229,
230,
231,
232,
233,
234,
235,
236,
237,
238,
239,
240,
241,
242,
243,
244,
245,
246,
247,
248,
249,
250,
251,
252,
253,
254,
255,
270,
271,
272,
273,
274,
275,
276,
277,
278,
279,
280,
281,
256,
133,
134,
135,
136,
137,
138,
139,
158,
159,
160,
161,
162,
163,
164,
165,
166,
167,
168,
169,
170,
257,
258,
259,
260,
261,
262,
263,
264,
288,
289,
290,
291,
292,
293,
294,
308,
309,
310,
311,
312,
313,
314,
315,
316,
317,
318,
319,
320,
321,
322,
323,
324,
325,
295,
296,
297,
298,
299,
300,
301,
302,
303,
304,
305,
265,
266,
267,
268,
269,
282,
283,
284,
342,
343,
344,
345,
346,
347,
348,
349,
350,
351,
352,
353,
354,
355,
356,
357,
358,
359,
360,
285,
286,
287,
306,
307,
326,
327,
328,
329,
330,
331,
332,
333,
334,
335,
336,
337,
338,
339,
340,
341,
361,
362,
363,
364,
365,
366,
367,
368,
369,
370,
371,
372,
394,
395,
396,
397,
398,
399,
400,
401,
402,
403,
404,
405,
406,
407,
408,
409,
410,
411,
412,
413,
414,
415,
416,
373,
421,
422,
423,
424,
449,
450,
451,
452,
453,
454,
455,
1,
2,
457,
458,
459,
460,
461,
425,
426,
427,
428,
429,
430,
378,
379,
380,
381,
382,
431,
374,
434,
435,
436,
437,
438,
439,
440,
441,
442,
443,
444,
445,
388,
389,
390,
391,
392,
393,
417,
418,
419,
420,
432,
433,
448,
462,
463,
464,
465,
466,
467,
468,
469,
470,
471,
472,
473,
474,
475,
476,
7,
8,
481,
482,
483,
484,
485,
486,
487,
488,
489,
490,
491,
492,
493,
499,
500,
501,
502,
446,
447,
375,
376,
377,
383,
384,
385,
386,
387,
503,
504,
505,
506,
507,
508,
509,
510
};





/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
