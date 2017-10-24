%%
%% This is file `tutthesis.cls',
%% This contains add-ons for report.cls file of the LaTeX base system.
%% Author: Sami Paavilainen (16 October 2006)
%% --------------------------------------------------------------
%% 
%% It may be distributed and/or modified under the
%% conditions of the LaTeX Project Public License, either version 1.3
%% of this license or (at your option) any later version.
%% The latest version of this license is in
%%    http://www.latex-project.org/lppl.txt
%% and version 1.3 or later is part of all distributions of LaTeX
%% version 2003/12/01 or later.
%% 
%% Modified: Erno Salminen, 2014-08-15, 
%%  - translated comments to English
%%  - includes package lstlistings for software codes, 
%%  - include packages hyperref and url for cross-references
%%  - page headers are not in uppercase anymore
%%  - minor tweaks
%%
%% ES, 2015-11-17 Geometry pakcage for 2-sided printing
%% ES, 2015-01-07 Minor/random changes...
%%  

\NeedsTeXFormat{LaTeX2e}[1995/12/01]
\ProvidesClass{uvmanual}
              [2014/07/28 v0.5 Extension to basic LaTeX document class 'report']

% Load the basic template 'report.cls'. 
\LoadClassWithOptions{report}


% TUT specific packages:
\RequirePackage[T1]{fontenc}     % produces scandinavian letters as output (dvi, pdf...), set this before inputenc
\RequirePackage{graphicx}        % for figures
\RequirePackage{psfrag}          % for editing ps files
\RequirePackage{subfig}       % parallel small figures a,b,c...
%\RequirePackage{wrapfig}         % put text around the fig
\RequirePackage{fancyhdr}        % prettier paging, http://www.ctan.org/tex-archive/macros/latex/contrib/fancyhdr/fancyhdr.pdf
%\RequirePackage{supertabular}    % tables over 1 page
\RequirePackage{rotating}        % rotate tables adn figures
\RequirePackage{amsmath}         % mathematics
\RequirePackage{setspace}        % line spacing

\usepackage[english]{babel}
\usepackage{enumitem}
\usepackage[section]{placeins} % Prevent figures from going to other sections
\usepackage{hyperref}       % pdf links to e.g. figures and citations
\usepackage{url}            % web links (URL)
\usepackage{mathptmx}
\usepackage{xcolor}% http://ctan.org/pkg/xcolor
\usepackage{titlesec} % For customizing chapters and sections
\usepackage{caption} % Figure caption text font and size, 
\usepackage{fontspec} % for custom fonts. Needs to be complied with XeLaTeX, nt PDFLatex!


\definecolor{uvc}{rgb}{0.294117647, 0.137254902, 0.462745098}
\definecolor{warningbg}{rgb}{1, 1, 0.741176471}


\defaultfontfeatures{Mapping=tex-text,Scale=MatchLowercase}
\setmainfont{Ek Mukta ExtraLight}


% Link colors
\hypersetup{
  colorlinks=true,
  linkcolor=uvc,
  urlcolor=uvc
}


% Defines the style for chapters
\titleformat{\chapter}[hang]
{\normalfont\LARGE\bfseries\color{uvc}}{\chaptertitlename\ \thechapter}{1em}{}[\vspace{2ex}\color{uvc}{\titlerule[2pt]}] 
\titlespacing*{\chapter}
{0pt}{1.0ex}{2.0ex}

% Defines the style for sections
\titleformat{\section}[hang] 
{\normalfont\large\bfseries\color{uvc}}{\chaptertitlename\ \thesection}{1em}{} 
\titlespacing*{\section}
{0pt}{1.0ex}{1.0ex}

% Defines the style for subsections
\titleformat{\subsection}[hang] 
{\normalfont\large\bfseries\color{uvc}}{\chaptertitlename\ \thesubsection}{1em}{} 

% Defines the style for subsubsections
\titleformat{\subsubsection}[hang] 
{\normalfont\large\bfseries\color{uvc}}{\chaptertitlename\ \thesubsubsection}{1em}{} 
\titlespacing*{\subsubsection}
{0pt}{-2ex}{0ex}




%
% Title page commands
%

% Create new types with 1 parameter (like \author} to print the basic
% info into title and abstract pages. At sign @denotes internal
% variable in Latex.
\def\titleB#1{\gdef\@titleB{#1}}
\def\@titleB{\@latex@warning@no@line{No \noexpand\titleB given}}


% Layout the title on 1st page (name, title, thesis type) in
% sans-serif font
\renewcommand\maketitle{
  \begin{center} 
      {\bf\Large \textsf{\MakeUppercase{\@title}}}
\end{center}
}



\newcommand\todo[1]{{\color{red}TODO: #1}}

\newcommand{\fig}[3] {\begin{figure}[ht]
	\centering
    \includegraphics[width=1.0\textwidth]{#1}
  \caption{#2}
  \label{fig:#3}
\end{figure}
}



\newcommand{\warning}[2] {%
\setlength{\fboxsep}{0pt}%
\colorbox{warningbg}{\begin{minipage}{15.5cm}%
\begin{tabular}{p{3cm} p{11cm}}%
\vspace{0pt}%
\includegraphics{img/warning.png}%
&%
\subsubsection{#1}#2%
\end{tabular}%
\end{minipage}%
}%
}


%Bullet spacing
\setitemize{itemsep=-7pt,topsep=0pt}






%
% TUT specific layout and font sizes
%
\setlength\textwidth{19cm}  % 15*24cm text area leaves 6cm horiz margins and 5.7cm vertical
\setlength\textheight{24cm} % 

\setlength\topmargin{0.0cm} % inner margins
\setlength\voffset{-1.25cm} % outer vertical   margins
\setlength\hoffset{0cm}     % outer horizontal margins
\setlength\oddsidemargin{1cm}  % inner margins for odd  pages
\setlength\evensidemargin{1cm} % inner margins for even pages
\setlength\brokenpenalty{1000} 
\renewcommand{\baselinestretch}{1.2}

% This package sounds promising but behaves sometimes strangely... (ES, 2014-11-17)
\usepackage[inner=2cm,outer=2cm,top=2cm, bottom=1cm]{geometry} %left=4cm,right=2cm would be equivalent

\setlength\headheight{15pt} % 
\setlength\headsep{0.8cm}   % space below header
\setlength\footskip{12pt}   % space above the footnote
\newcommand\chapfigname{\thechapter}
