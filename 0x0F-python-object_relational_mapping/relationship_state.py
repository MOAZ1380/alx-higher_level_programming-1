#!/usr/bin/python3

"""
A script that defines model via SQLAlchemy ORM
"""
from sqlalchemy import Column, Integer, String
from sqlalchemy.orm import relationship
from relationship_city import Base


class State(Base):
    """
    Defines a state model
    """
    __tablename__: str = 'states'
    id: Column = Column(Integer, primary_key=True, nullable=False)
    name: Column = Column(String(128), nullable=False)
    cities: relationship = relationship(
        'City', backref='state', cascade='all, delete'
    )
