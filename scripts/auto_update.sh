#!/bin/bash

cd ~/stocks_news
cmd='./stocksnews Paris --update'
$cmd >> log.txt
