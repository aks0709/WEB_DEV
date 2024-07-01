import React from "react";
import ReactDom from "react.dom/client";
console.log('HELLO PP');
const heading=React.createElement('h2',{},"Hello");
const domRoot=document.getElementById('root');
const reactRoot=ReactDom.createRoot(domRoot);
reactRoot.Render(heading);
domRoot.appendChild(heading);
